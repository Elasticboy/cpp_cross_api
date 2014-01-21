#pragma once

#include "platform_config.h"
#if defined(WINDOWS_PLATFORM)

#include "../voice.h"
#include <vector>
#include <string>

#include <comdef.h>
#include <sphelper.h>

namespace text_to_speech
{
	void init_voice(ISpVoice * ispVoice, const language_code& language, const std::string& gender, const tts_age& age, const long& rate=0);

	const std::wstring lang_as_attribute(const language_code& language);
	const std::wstring gender_as_attribute(const std::string& gender);
	const std::wstring age_as_attribute(const tts_age& age);
}

#endif
