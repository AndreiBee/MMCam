#include "Motor.h"
/* Motor */

Motor::Motor()
{
	m_MotorSettings = std::make_unique<MotorVariables::Settings>();
	m_StandaSettings = std::make_unique<StandaVariables::C_Settings>();
}

auto Motor::GetDeviceSerNum() const
{
	return m_SerNum;
}

auto Motor::GetDeviceRange() const
{
	return m_MotorSettings->stageRange;
}

auto Motor::GetDeviceActualStagePos() const
{
	return m_MotorSettings->stagePos;
}

auto Motor::SetDeviceName(const char* device_name)
{
	size_t char_count{};
	while (*device_name != '\0')
	{
		++char_count;
		++device_name;
	}
	device_name -= char_count;

	m_DeviceName = std::make_unique<char[]>(char_count + 1);
	//strncpy(m_DeviceName.get(), device_name, char_count);
	memcpy(m_DeviceName.get(), device_name, char_count);
	m_DeviceName[char_count] = '\0';
}

auto Motor::SetSerNum(unsigned int s_n)
{
	m_SerNum = s_n;
}

auto Motor::SetResult(result_t result)
{
	m_StandaSettings->result = result;
}

auto Motor::SetCalibration(calibration_t calibration)
{
	m_StandaSettings->calibration = calibration;
}

auto Motor::SetState(status_t state)
{
	m_StandaSettings->state = state;
}

auto Motor::SetCalbState(status_calb_t calb_state)
{
	m_StandaSettings->calb_state = calb_state;
}

auto Motor::SetRange(const float min_motor_deg, const float max_motor_deg)
{
	/* Min position */
	m_MotorSettings->minMotorPos = min_motor_deg;
	m_MotorSettings->minStagePos = min_motor_deg / deg_per_mm;

	/* Middle position */
	m_MotorSettings->middleMotorPos = (max_motor_deg - min_motor_deg) / 2.f;
	m_MotorSettings->middleStagePos = m_MotorSettings->middleMotorPos / deg_per_mm;

	/* Max position */
	m_MotorSettings->maxMotorPos = max_motor_deg;
	m_MotorSettings->maxStagePos = max_motor_deg / deg_per_mm;

	/* Set Whole Motor Range */
	m_MotorSettings->motorRange = max_motor_deg - min_motor_deg;
	m_MotorSettings->stageRange = (max_motor_deg - min_motor_deg) / deg_per_mm;
}

auto Motor::UpdateCurPosThroughStanda()
{
	m_MotorSettings->motorPos = m_StandaSettings->state.CurPosition;
	m_MotorSettings->stagePos = m_StandaSettings->state.CurPosition / deg_per_mm;
}

auto Motor::GoCenter()
{
	device_t device_c;
	device_c = open_device(m_DeviceName.get());

	{
		if ((m_StandaSettings->result = command_move_calb
		(
			device_c, 
			m_MotorSettings->middleMotorPos, 
			&m_StandaSettings->calibration
		)
			) != result_ok)
		{
			/* Error command_move_calb */
			return false;
		}
		/* Wait to Stop */
		if ((m_StandaSettings->result = command_wait_for_stop
		(
			device_c, 
			100
		)
			) != result_ok)
		{
			/* Error command_wait_for_stop */
			return false;
		}
		/* Wait for elimination of vibrations */
		std::this_thread::sleep_for(std::chrono::milliseconds(wait_delay_milliseconds));
		/* Get Status */
		if ((m_StandaSettings->result = get_status
		(
			device_c, 
			&m_StandaSettings->state 
		)
			) != result_ok)
		{
			/* Error getting status */
			return false;
		}
		/* Get Calibrated Status */
		if ((m_StandaSettings->result = get_status_calb
		(
			device_c, 
			&m_StandaSettings->calb_state, 
			&m_StandaSettings->calibration
		)
			) != result_ok)
		{
			/* Error getting status */
			return false;
		}
	}

	close_device(&device_c);

	UpdateCurPosThroughStanda();
}

auto Motor::GoHomeAndZero()
{
	device_t device_c;
	device_c = open_device(m_DeviceName.get());

	{
		if ((m_StandaSettings->result = command_homezero(device_c) != result_ok)) return false;
		/* Wait to Stop */
		if ((m_StandaSettings->result = command_wait_for_stop
		(
			device_c, 
			100
		)
			) != result_ok)
		{
			/* Error command_wait_for_stop */
			return false;
		}
		/* Wait for elimination of vibrations */
		std::this_thread::sleep_for(std::chrono::milliseconds(wait_delay_milliseconds));
		/* Get Status */
		if ((m_StandaSettings->result = get_status
		(
			device_c, 
			&m_StandaSettings->state 
		)
			) != result_ok)
		{
			/* Error getting status */
			return false;
		}
		/* Get Calibrated Status */
		if ((m_StandaSettings->result = get_status_calb
		(
			device_c, 
			&m_StandaSettings->calb_state, 
			&m_StandaSettings->calibration
		)
			) != result_ok)
		{
			/* Error getting status */
			return false;
		}
	}

	close_device(&device_c);

	UpdateCurPosThroughStanda();
}

auto Motor::GoToPos(const float stage_position)
{
	device_t device_c;
	device_c = open_device(&m_DeviceName[0]);

	/* Get Status */
	if ((m_StandaSettings->result = get_status_calb
	(
		device_c, 
		&m_StandaSettings->calb_state, 
		&m_StandaSettings->calibration
	)
		) != result_ok)
	{
		/* Error getting status */
		return false;
	}

	/* If stage_position is outside of motor's range -> return */
	if (stage_position < m_MotorSettings->minStagePos || 
		stage_position > m_MotorSettings->maxStagePos)
		return false;

	{
		float motor_position = stage_position * deg_per_mm;
		if ((m_StandaSettings->result = command_move_calb
		(
			device_c, 
			motor_position, 
			&m_StandaSettings->calibration
		) != result_ok)) 
			return false;
		/* Wait to Stop */
		if ((m_StandaSettings->result = command_wait_for_stop
		(
			device_c, 
			100
		)
			) != result_ok)
		{
			/* Error command_wait_for_stop */
			return false;
		}
		/* Wait for elimination of vibrations */
		std::this_thread::sleep_for(std::chrono::milliseconds(wait_delay_milliseconds));
		/* Get Status */
		if ((m_StandaSettings->result = get_status
		(
			device_c, 
			&m_StandaSettings->state 
		)
			) != result_ok)
		{
			/* Error getting status */
			return false;
		}
		/* Get Calibrated Status */
		if ((m_StandaSettings->result = get_status_calb
		(
			device_c, 
			&m_StandaSettings->calb_state, 
			&m_StandaSettings->calibration
		)
			) != result_ok)
		{
			/* Error getting status */
			return false;
		}
	}
	close_device(&device_c);

	UpdateCurPosThroughStanda();
}

/* MotorArray */
MotorArray::MotorArray()
{
	InitAllMotors();
}

auto MotorArray::FillNames()
{
	for (const auto& motor : m_MotorsArray)
	{
		m_NamesOfMotorsWithRanges.emplace(std::make_pair(motor.GetDeviceSerNum(), motor.GetDeviceRange()));
	}
}

std::map<unsigned int, float> MotorArray::GetNamesWithRanges() const
{
	return m_NamesOfMotorsWithRanges;
}

float MotorArray::GetActualStagePos(const int& motor_number) const
{
	return motor_number >= m_MotorsArray.size() || motor_number < 0 ? 0.f : m_MotorsArray[motor_number].GetDeviceActualStagePos();
}

bool MotorArray::MotorHasSerialNumber(const int& motor_number) const
{
	return motor_number >= m_MotorsArray.size() || motor_number < 0 ? false : m_MotorsArray[motor_number].GetDeviceSerNum();
}

float MotorArray::GoMotorHome(const int& motor_number)
{
	if (motor_number >= m_MotorsArray.size() || motor_number < 0) return 0.f;
	m_MotorsArray[motor_number].GoHomeAndZero();
	return m_MotorsArray[motor_number].GetDeviceActualStagePos();
}

float MotorArray::GoMotorCenter(const int& motor_number)
{
	if (motor_number >= m_MotorsArray.size() || motor_number < 0) return 0.f;
	m_MotorsArray[motor_number].GoCenter();
	return m_MotorsArray[motor_number].GetDeviceActualStagePos();
}

float MotorArray::GoMotorToAbsPos(const int& motor_number, float abs_pos)
{
	if (motor_number >= m_MotorsArray.size() || motor_number < 0) return 0.f;
	if (abs_pos < 0.f || abs_pos > m_MotorsArray[motor_number].GetDeviceRange()) return abs_pos;
	m_MotorsArray[motor_number].GoToPos(abs_pos);
	return m_MotorsArray[motor_number].GetDeviceActualStagePos();
}

float MotorArray::GoMotorOffset(const int& motor_number, float offset)
{	
	if (motor_number >= m_MotorsArray.size() || motor_number < 0) return 0.f;
	if (offset + m_MotorsArray[motor_number].GetDeviceActualStagePos() < 0.f || 
		offset + m_MotorsArray[motor_number].GetDeviceActualStagePos() > m_MotorsArray[motor_number].GetDeviceRange()) 
		return m_MotorsArray[motor_number].GetDeviceActualStagePos();
	m_MotorsArray[motor_number].GoToPos(m_MotorsArray[motor_number].GetDeviceActualStagePos() + offset);
	return m_MotorsArray[motor_number].GetDeviceActualStagePos();
}

bool MotorArray::InitAllMotors()
{
	result_t result_c;
	result_c = set_bindy_key("keyfile.sqlite");
	if (result_c != result_ok) return false;

	device_enumeration_t devenum_c;
	const int probe_flags = ENUMERATE_PROBE | ENUMERATE_NETWORK;
	const char* enumerate_hints = "addr=";
	devenum_c = enumerate_devices(probe_flags, enumerate_hints);
	if (!devenum_c) return false;

	int names_count = get_device_count(devenum_c);
	/* Here we need to clear motor list */
	m_MotorsArray.clear();
	m_MotorsArray.reserve(names_count);

	char device_name[256];
	device_t device_c;
	status_t state_c;
	status_calb_t state_calb_c;
	calibration_t calibration_c;
	edges_settings_calb_t edges_settings_calb_c;
	unsigned int device_sn{};
	for (int i = 0; i < names_count; ++i)
	{
		m_MotorsArray.emplace_back(Motor());
		m_MotorsArray[i].SetResult(result_c);

		strcpy(device_name, get_device_name(devenum_c, i));
		m_MotorsArray[i].SetDeviceName(device_name);
		device_c = open_device(device_name);
		get_serial_number(device_c, &device_sn);
		m_MotorsArray[i].SetSerNum(device_sn);

		if ((result_c = get_status(device_c, &state_c)) != result_ok)
			return false;

		const char* correction_table = "table.txt";
		// The device_t device parameter in this function is a C pointer, unlike most library functions that use this parameter
		if ((result_c = set_correction_table(device_c, correction_table)) != result_ok)
			return false;

		calibration_c.A = 1;
		calibration_c.MicrostepMode = MICROSTEP_MODE_FULL;
		m_MotorsArray[i].SetCalibration(calibration_c);

		/* Get Status */
		if ((result_c = get_status_calb(device_c, &state_calb_c, &calibration_c)) != result_ok) return false;
		m_MotorsArray[i].SetState(state_c);

		get_edges_settings_calb(device_c, &edges_settings_calb_c, &calibration_c);
		m_MotorsArray[i].SetRange(edges_settings_calb_c.LeftBorder, edges_settings_calb_c.RightBorder);

		m_MotorsArray[i].UpdateCurPosThroughStanda();

		close_device(&device_c);
	}
	free_enumerate_devices(devenum_c);
	FillNames();
}
