#ifndef UNITTEST_TESTREPORTEREVERYTESTTOSTDOUT_H
#define UNITTEST_TESTREPORTEREVERYTESTTOSTDOUT_H

#include "TestReporter.h"

namespace UnitTest {

class TestReporterEveryTestToStdout : public TestReporter
{
private:
    virtual void ReportTestStart(TestDetails const& test);
    virtual void ReportFailure(TestDetails const& test, char const* failure);
    virtual void ReportTestFinish(TestDetails const& test, float millisecondsElapsed);
    virtual void ReportSummary(int totalTestCount, int failedTestCount, int failureCount, float secondsElapsed);
};

}

#endif 
