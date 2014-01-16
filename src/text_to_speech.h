#pragma once

#include "platform_config.h"
# if defined(WINDOWS_PLATFORM)
#	include "windows/text_to_speech_windows.h"
# else
#	include "unix/text_to_speech_unix.h"
# endif

#include "voice.h"

#include <string>
#include <vector>

namespace text_to_speech {
	namespace languague
	{
		const std::string EN = "EN";
		const std::string FR = "FR";
	};

	const std::string default_lang = languague::EN;

	std::vector<std::string> available_languages();
	bool test_parameters(const language_code& language, const std::string& gender, const tts_age& age, const long& rate);
	bool say(const std::string& textToSpeak, const language_code& language, const std::string& gender, const tts_age& age, const long& rate);
}
