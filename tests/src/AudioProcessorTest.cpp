#include <catch2/catch_test_macros.hpp>
#include <PluginProcessor.h>

TEST_CASE("AudioProcessor Initialization", "[audio]") {
  
  AudioPluginAudioProcessor processor{};
  
  SECTION("Default State") {
    REQUIRE(true);
  }
}








