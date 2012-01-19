#include <UnitTest++/UnitTest++.h>

namespace {
	int RunTests() {
//		Log::ShowMessageTypes(Severity::None);

		const int fail_count = UnitTest::RunAllTests();
//		const int leak_count = MemoryTracker::ReportLeaks();

		return fail_count;// + leak_count;
	}
}

int main() {
	return RunTests();
}