#pragma once

typedef struct _TimingPointType {
    /* https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)#timing-points */
    int Offset;
    double MillisecondsPerBeat;
    /*
    double bpm() {
    // Exclusive if's to avoid division by 0
    if(millisecondsPerBeat > 0) return 60000.0 / millisecondsPerBeat;
    else if (millisecondsPerBeat < 0) return 60000.0 / ((millisecondsPerBeat / -100.0) * lastPositive);
    return 0.0; // Catch-all for 0 and unexpected values
    }
    */
    int Meter;
    int SampleSet;
    int SampleIndex;
    int Volume;
    bool Inherited;
    bool Kiai;
} TimingPoint;