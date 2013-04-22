#include "voice.h"


namespace text_to_speech {

	voice::voice(const std::string& name, const language_code& language, const std::string& gender, const long& rate)
	: name_(name), language_(language), gender_(gender), rate_(rate), is_mute_(false) { }


	std::string voice::name() const
	{
		return name_;
	}

	void voice::set_name(const std::string& name)
	{
		name_ = name;
	}

	language_code voice::language() const
	{
		return language_;
	}
	
	void voice::set_language(const language_code& language)
	{
		language_ = language;
	}

	std::string voice::gender() const
	{
		return gender_;
	}

	void voice::set_gender(const std::string& gender)
	{
		gender_ = gender;
	}

	bool voice::is_mute() const
	{
		return is_mute_;
	}

	void voice::set_is_mute(const bool& is_mute)
	{
		is_mute_ = is_mute;
	}

	long voice::rate() const
	{
		return rate_;
	}
	
	void voice::set_rate(const long& rate)
	{
		rate_ = rate;
	}

}