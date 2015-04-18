#include "platform_config.h"

#if defined(UNIX_PLATFORM)

#include "../text_to_speech.h"

#include <vector>

namespace text_to_speech
{
    bool is_implemented() { return false; }

    std::vector<std::string> available_languages()
    {
        // TODO: Find a way to implement text_to_speech::available_languages()
        return std::vector<std::string>();
    }

    bool test_parameters(const language_code& language, const std::string& gender, const tts_age& age, const long& rate)
    {
        // TODO: Implement text_to_speech::testParameters() for Linux
        return false;
    }

    bool say(const std::string &textToSpeak, const language_code &language, const std::string &gender, const tts_age &age, const long &rate)
    {
        // TODO: Implement text_to_speech::say() for Linux
        return false;
    }
}

#endif
