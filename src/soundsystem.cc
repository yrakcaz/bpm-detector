#include <iostream>

#include <soundsystem.hh>

SoundSystem::~SoundSystem()
{
    delete[] left_data_;
    delete[] right_data_;
}

void SoundSystem::load(const char* path)
{
    SF_INFO info;
    SNDFILE* sf = sf_open(path, SFM_READ, &info);
    if (!sf)
    {
        std::cerr << "bpm-detector: failed to open file: " << sf_strerror(nullptr) << std::endl;
        return;
    }
    len_ = info.frames;
    left_data_ = new int[len_];
    right_data_ = new int[len_];
    int* buf = new int[len_ * info.channels];
    sf_readf_int(sf, buf, len_);
    for (unsigned int i = 0; i < len_; i++)
    {
        left_data_[i] = buf[i * info.channels] >> 16;
        right_data_[i] = (info.channels > 1 ? buf[i * info.channels + 1]
                                             : buf[i * info.channels]) >> 16;
    }
    delete[] buf;
    sf_close(sf);
}

const int* SoundSystem::left_data_get() const
{
    return left_data_;
}

const int* SoundSystem::right_data_get() const
{
    return right_data_;
}

unsigned int SoundSystem::len_get() const
{
    return len_;
}
