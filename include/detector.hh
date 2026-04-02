#ifndef DETECTOR_HH
# define DETECTOR_HH

# include <vector>

# include "soundsystem.hh"

// Size of a song sample window.
# define WINDOW 4096

// Ratio threshold for peak detection.
# define RATIO 1.3

// BPM detector: analyzes audio energy and detects peaks to compute tempo.
class Detector
{
    public:
        // Constructor taking an initialized SoundSystem.
        Detector(const SoundSystem& system);
        // Default destructor.
        ~Detector();

        // Returns the computed BPM of the song.
        int bpm_get();

    private:
        // Calculates the energy of a song sample at the given offset.
        int nrj_get(const int* data, int offset);
        // Fills the energy peaks array.
        void peaks_set();
        // Fills the laps array.
        void laps_set();
        // Normalizes bpm by halving or doubling until it falls in [70, 200].
        double normalize(double bpm);

    private:
        // SoundSystem containing the initialized song.
        const SoundSystem& system_;
        // Energy vector (1024-sample windows).
        std::vector<double> nrj1024_;
        // Energy vector (44100-sample windows).
        std::vector<double> nrj44100_;
        // Energy peak positions.
        std::vector<bool> peaks_;
        // Distances between energy peaks.
        std::vector<int> laps_;
};

#endif /* !DETECTOR_HH */
