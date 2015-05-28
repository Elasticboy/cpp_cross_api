#pragma once

#include <string>

namespace text_to_speech
{
    enum language_code { en_US, en_UK, fr_FR };

    enum tts_age { Child, Teen, Adult, Senior };

    class voice
    {
    public:
        voice(const std::string& name, const language_code& language, const std::string& gender, const tts_age& age, const long& rate = 0);

        void say_async(const std::string& textToSpeak);

        std::string name() const;

        language_code language() const;

        std::string gender() const;

        bool is_mute() const;

        long rate() const;

        void set_name(const std::string& name);

        void set_language(const language_code& language);

        void set_gender(const std::string& gender);

        void set_tts_name(const std::string& tts_name);

        void set_age(const tts_age& age);

        void set_is_mute(const bool& is_mute);

        void set_rate(const long& rate);

    private:
        std::string name_;
        language_code language_;
        std::string gender_;
        std::string tts_name_;
        tts_age age_;
        bool is_mute_;
        long rate_;

        void say(const std::string& textToSpeak);
    };
}