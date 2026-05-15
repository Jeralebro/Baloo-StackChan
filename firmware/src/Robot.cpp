#include "Robot.h"
#include "llm/Grok/Grok.h"   // Grok LLM
#include "llm/ChatGPT/ChatGPT.h"  // kept for compatibility
#include <M5Unified.h>

Robot::Robot() : llm(nullptr) {}

Robot::~Robot() {
    if (llm) delete llm;
}

void Robot::initLLM(StackchanExConfig& config) {
    SecretConfig* api_key = config.getSecretConfig();
    if (api_key == nullptr) {
        Serial.println("API key not found");
        return;
    }

    llm_param_t llm_param;
    llm_param.api_key = api_key->ai_service;

    // Baloo uses Grok by default (Phase 0 - English foundation)
    Serial.println("Initializing Grok LLM for Baloo...");
    llm = new Grok(llm_param);

    if (llm == nullptr) {
        Serial.println("Failed to create LLM instance");
    } else {
        Serial.println("LLM initialized successfully (Grok)");
    }
}

// Other Robot methods can be added here if your original file had more.
// If you had custom code in the old Robot.cpp, merge it in after this builds.