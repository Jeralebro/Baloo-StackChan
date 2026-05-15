#include "ChatGPT.h"
#include "FunctionCall.h"
#include "../SpiRamJsonDocument.h"
#include <HTTPClient.h>

// Prompt index constants (were missing)
const int SYSTEM_PROMPT_INDEX_SYSTEM_ROLE = 0;
const int SYSTEM_PROMPT_INDEX_USER_ROLE   = 1;
const int SYSTEM_PROMPT_INDEX_USER_INFO   = 2;

// Stub implementations so class is no longer abstract
String ChatGPT::listen() {
    return "";  // STT handled outside LLM layer
}

ChatGPT::ChatGPT(llm_param_t param, int _promptMaxSize)
    : LLMBase(param, _promptMaxSize), _param(param), promptMaxSize(_promptMaxSize) {
    load_role();
}

void ChatGPT::load_role() {
    // Simple Baloo-friendly defaults (will be replaced by full system prompt later)
    defaultRole = "You are Baloo, a warm, playful, honest bear from The Jungle Book.";
    systemRole = defaultRole;
    userInfo = "";
    role = defaultRole;
}

String ChatGPT::https_post_json(const char* url, const char* json_string, const char* content_type) {
    // Stub - real call not needed since we use Grok
    return R"({"choices":[{"message":{"content":"[ChatGPT stub response]"}}]})";
}

String ChatGPT::execChatGpt(String text, String& calledFunc) {
    calledFunc = "";
    return "ChatGPT placeholder - Grok is the active LLM for Baloo.";
}

void ChatGPT::chat(String text, const char* base64_buf) {
    String calledFunc = "";
    String response = execChatGpt(text, calledFunc);
    // TODO: full implementation only if you switch back to ChatGPT
}

String ChatGPT::mcp_call_tool(DynamicJsonDocument& tool_params) {
    return "";
}