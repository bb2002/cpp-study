#pragma once
#include<iostream>
#include<string>
namespace SaintDoorEngine {
	const int DR_OPEN = 1;
	const int DR_CLOSE = 0;

	struct Door {
		void Open();
		void Close();
		void ShowState() const;

		void SetName(std::string s);
		std::string GetName();
		void State(int i);

		int state;
		std::string name;
	};

	inline void SaintDoorEngine::Door::State(int i) {
		state = i;
	}
}