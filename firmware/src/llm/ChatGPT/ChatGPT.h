#pragma once

#include "../LLMBase.h"
#include "FunctionCall.h"
#include <ArduinoJson.h>

#define CHATGPT_PROMPT_MAX_SIZE 3000

class ChatGPT : public LLMBase {
public:
    ChatGPT(llm_param_t param, int _promptMaxSize = CHATGPT_PROMPT_MAX_SIZE);
    virtual ~ChatGPT() {}

    // Required by LLMBase
    virtual String listen() override;
    virtual void chat(String text, const char* base64_buf = NULL) override;

    virtual void load_role() override;
    virtual String execChatGpt(String text, String& calledFunc) override;
    virtual String https_post_json(const char* url, const char* json_string, const char* content_type) override;

    String mcp_call_tool(DynamicJsonDocument& tool_params);

private:
    llm_param_t _param;
    int promptMaxSize;

    bool _enableMemory = false;
    String defaultRole;
    String systemRole_memory;
    String systemRole_noMemory;
    String systemRole;
    String userInfo;
    String role;
};

#endif