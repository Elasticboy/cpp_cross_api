#pragma once

#include "voice.h"

#include <string>
#include <vector>

namespace text_to_speech
{
    namespace languague
    {
        const std::string EN = "EN";
        const std::string FR = "FR";
    };

    const std::string default_lang = languague::EN;

    /** @return True if text-to-speech is implemented for the current platform. */
    bool is_implemented();

    std::vector <std::string> available_languages();

    /**
     * Try to initialize a voice object to check if the properties are OK.
     * @return True if parameters are correct, false otherwise.
     * @throws and Exception if a problem occurs.
     */
    bool test_parameters(const language_code& language, const std::string& gender, const tts_age& age, const long& rate);

    bool say(const std::string& textToSpeak, const language_code& language, const std::string& gender, const tts_age& age, const long& rate);
}
