cmake_minimum_required(VERSION 3.22)

project(MisterEcho VERSION 0.1.0)

juce_add_plugin(
    ${PROJECT_NAME}
    COMPANY_NAME "${COMPANY_NAME}"
    PLUGIN_MANUFACTURER_CODE "PEML"
    PLUGIN_CODE "MREC"
    FORMATS AU VST3 Standalone
    PRODUCT_NAME ${PRODUCT_NAME}
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
)


target_sources(${PROJECT_NAME}
    PRIVATE
        src/PluginProcessor.cpp
        src/PluginEditor.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

if(MSVC)
    # Disable warnings-as-errors for juce_vst3_helper
    set_target_properties(juce_vst3_helper PROPERTIES COMPILE_OPTIONS "/WX-")
endif()