#ifndef SOUNDSYSTEM_HH
# define SOUNDSYSTEM_HH

# include <sndfile.h>

// libsndfile wrapper for audio loading.
class SoundSystem
{
    public:
        // Default constructor.
        SoundSystem() = default;
        // Default destructor.
        ~SoundSystem();

        // Loads the song at the given path.
        void load(const char* path);

        // Returns the left channel audio data.
        const int* left_data_get() const;
        // Returns the right channel audio data.
        const int* right_data_get() const;
        // Returns the song length in frames.
        unsigned int len_get() const;

    private:
        // Left channel audio data.
        int* left_data_ = nullptr;
        // Right channel audio data.
        int* right_data_ = nullptr;
        // Song length in frames.
        unsigned int len_ = 0;
};

#endif /* !SOUNDSYSTEM_HH */
