#include "voice.h"

#include <thread>
#include "text_to_speech.h"
#include "Utils.h"

namespace text_to_speech {

	voice::voice(const std::string& name, const language_code& language, const std::string& gender, const tts_age& age, const long& rate)
		: name_(name), language_(language), gender_(gender), age_(age), tts_name_(""), rate_(rate), is_mute_(false) { }
	
	// TODO rename in voice::say ? 
	void voice::say_async(const std::string& textToSpeak)
	{
		//std::thread speakThread(&voice::say, this, textToSpeak);
		std::thread speakThread(&text_to_speech::say, textToSpeak, language_, gender_, age_, rate_);
		speakThread.join();
	}

	// TODO Remove voice::say 
	void voice::say(const std::string& textToSpeak)
	{
		text_to_speech::say(textToSpeak, language_, gender_, age_, rate_);
	}

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