#pragma once
#ifndef MOTOR_H
#define MOTOR_H
#include <memory>
#include <map>
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
		float MotorRange{}, StageRange{};
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
	auto GetDeviceRange() const;
	auto GetDeviceActualStagePos() const;

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
	bool InitAllMotors();
	auto FillNames();

	/* Getter */
	std::map<unsigned int, float> GetNamesWithRanges() const;
	float GetActualStagePos(const int& motor_number) const;
	bool MotorHasSerialNumber(const int& motor_number) const;

	/* Setter */
	float GoMotorHome(const int& motor_number);
	float GoMotorCenter(const int& motor_number);
	float GoMotorToAbsPos(const int& motor_number, float abs_pos);

private:
	std::vector<Motor> m_MotorsArray{};
	std::map<unsigned int, float> m_NamesOfMotorsWithRanges{};
};

#endif
