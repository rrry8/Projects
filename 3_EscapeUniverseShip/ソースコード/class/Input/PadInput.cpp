#include<DxLib.h>
#include "PadInput.h"

PadInput::PadInput()
{
	inputTable_ = {
	{KeyID::Up,PAD_INPUT_UP},
	{KeyID::Down,PAD_INPUT_DOWN},
	{KeyID::Left,PAD_INPUT_LEFT},
	{KeyID::Right,PAD_INPUT_RIGHT},
	{KeyID::Decide,PAD_INPUT_1},
	{KeyID::Cancel,PAD_INPUT_2},
	{KeyID::Pause,PAD_INPUT_3},
	{KeyID::Button,PAD_INPUT_4}
	};

	for (auto& data : inputTable_)
	{
		controllerData_.try_emplace(data.first, AgeBool{ 0,0 });
	}
}

PadInput::~PadInput()
{
}

void PadInput::Update(void)
{
	auto PadData = GetJoypadInputState(DX_INPUT_PAD1);
	for (auto id : KeyID())
	{
		controllerData_[id][static_cast<int>(ControllerAge::Old)] = controllerData_[id][static_cast<int>(ControllerAge::Now)];
		controllerData_[id][static_cast<int>(ControllerAge::Now)] = (PadData & inputTable_[id]) > 0;
	}
}
