#include "TestReporterEveryTestToStdout.h"
#include <cstdio>

#include "TestDetails.h"

namespace UnitTest {

void TestReporterEveryTestToStdout::ReportFailure(TestDetails const& details, char const* failure)
{
#ifdef __APPLE__
    char const* const errorFormat = "%s:%d: error: Failure in %s: %s\n";
#else
    char const* const errorFormat = "%s(%d): error: Failure in %s: %s\n";
#endif
    std::printf(errorFormat, details.filename, details.lineNumber, details.testName, failure);
}

void TestReporterEveryTestToStdout::ReportTestStart(TestDetails const& test)
{
	std::printf("Running %s... ", test.testName);
	_flushall();
}

void TestReporterEveryTestToStdout::ReportTestFinish(TestDetails const& /*test*/, float millisecondsElapsed)
{
	std::printf("Finished in %.0f milliseconds.\n", millisecondsElapsed);
	_flushall();
}

void TestReporterEveryTestToStdout::ReportSummary(int const totalTestCount, int const failedTestCount,
                                       int const failureCount, float secondsElapsed)
{
    if (failureCount > 0)
        std::printf("FAILURE: %d out of %d tests failed (%d failures).\n", failedTestCount, totalTestCount, failureCount);
    else
        std::printf("Success: %d tests passed.\n", totalTestCount);
    std::printf("Test time: %.2f seconds.\n", secondsElapsed);
}

}
