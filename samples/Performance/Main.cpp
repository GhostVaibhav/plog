﻿#include <plog/Log.h>
#include <plog/Appenders/ConsoleAppender.h>

enum
{
    Console = 1
};

int main()
{
    plog::init(plog::debug, "Performance.txt");

    plog::ConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init<Console>(plog::debug, &consoleAppender);

    LOGI_(Console) << "Test started";

    const int kCount = 50000;

    plog::util::Time startTime;
    plog::util::ftime(&startTime);

    for (int i = 0; i < kCount; ++i)
    {
        LOGD << "Hello log!";
    }

    plog::util::Time finishTime;
    plog::util::ftime(&finishTime);

    time_t timeDiff = (finishTime.millitm - startTime.millitm) + (finishTime.time - startTime.time) * 1000;

    LOGI_(Console) << "Test finished: " << timeDiff * 1000. / kCount << " microsec per call";

    return 0;
}