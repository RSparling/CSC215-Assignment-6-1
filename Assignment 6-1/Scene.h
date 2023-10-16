#pragma once
/*
Defines Scenes and Options to allow for easy use elsewhere.
*/
#include <string>
#include <vector>
using namespace std;

struct Option {
public:
	Option(const string& text, const string& success, const string& fail, char requiredResource, int requiredAmmount, int money, int food, int energy)
		: text(text), successText(success), failureText(fail), requiredResource(requiredResource), requiredAmmount(requiredAmmount), money(money), food(food), energy(energy)
	{
	}

	string GetOptionText() {
		return text;
	}

	string GetSuccessText() {
		return successText;
	}

	string GetFailText() {
		return failureText;
	}

	char GetRequiredResource() {
		return requiredResource;
	}

	char GetRequiredAmmount() {
		return requiredAmmount;
	}

	bool IsSpecial() {
		if (requiredResource == 's')
			return true;
		return false;
	}
	vector<int> GetConsequences() {
		vector<int> consequences;
		consequences.push_back(energy);
		consequences.push_back(food);
		consequences.push_back(money);
		return consequences;
	}
private:
	//the text displayed for the option
	string text;
	string successText;
	string failureText;
	char requiredResource;
	int requiredAmmount;
	//consequences, a +/- to the player current resources
	int money;
	int food;
	int energy;
};

struct Scene {
public:
	//intialize with assignment constructor list
	Scene(string text) :text(text) {}
	Scene() {};
	Scene AddOption(Option option) {//allows a build pattern to be used to add options;
		options.push_back(option);
		return *this;
	}

	string GetText() {
		return text;
	}

	vector<Option> GetOptions() {
		return options;
	}

	Option GetOption(int index) {
		return options[index];
	}
private:
	string text;
	vector<Option> options;
};