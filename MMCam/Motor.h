#pragma once
#ifndef MOTOR_H
#define MOTOR_H
#include <memory>
#include <vector>
#include <ximc.h>

namespace MotorVariables
{
	struct Settings
	{
		float MotorPos{};
		float MinMotorPos{}, MiddleMotorPos{}, MaxMotorPos{};
		float StagePos{};
		float MinStagePos{}, MiddleStagePos{}, MaxStagePos{};
		float MotorRange{};
	};
}

namespace StandaVariables
{
	struct C_Settings
	{
		result_t Result{};
		calibration_t Calibration{};
		status_calb_t State{};
	};
}

class Motor final
{
public:
	Motor();
	/* Getters */
	auto GetDeviceSerNum() const;

	/* Setters */
	auto SetDeviceName(const char* device_name);
	auto SetSerNum(unsigned int s_n);
	auto SetResult(result_t result);
	auto SetCalibration(calibration_t calibration);
	auto SetState(status_calb_t state);
	auto SetRange(const float min_motor_deg, const float max_motor_deg);


	auto UpdateCurPosThroughStanda();
	auto GoCenter();
	auto GoHomeAndZero();
	auto GoToPos(const float stage_position);

private:
	std::unique_ptr<MotorVariables::Settings> m_MotorSettings{};
	std::unique_ptr<StandaVariables::C_Settings> m_StandaSettings{};
	const float deg_per_mm{ 800.f }; // Hardcoded
	std::unique_ptr<char[]> m_DeviceName{};
	unsigned int m_SerNum{};
};

class MotorArray final
{
public:
	MotorArray();
	auto InitAllMotors();

private:
	std::vector<Motor> m_MotorsArray{};
};

#endif
