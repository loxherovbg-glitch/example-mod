#include <Geode/Geode.hpp>
#include <Geode/modify/CCApplication.hpp>

using namespace geode::prelude;

 patch-1
void updateCustomFPS() {
    auto fpsValue = Mod::get()->getSettingValue<double>("fps-limit");
    auto enabled = Mod::get()->getSettingValue<bool>("enable-bypass");

    if (enabled) {
        CCDirector::sharedDirector()->setAnimationInterval(1.0 / fpsValue);
    } else {
        CCDirector::sharedDirector()->setAnimationInterval(1.0 / 60.0);
    }
}

class $modify(CCApplication) {
    void setupGLView() {
        CCApplication::setupGLView();
        updateCustomFPS();
    }
};

$execute {
    listenForSettingChanges("enable-bypass", [](bool) {
        updateCustomFPS();
    });
    listenForSettingChanges("fps-limit", [](double) {
        updateCustomFPS();
    });
}


class $modify(CCApplication) {
    void setupGLView() {
        CCApplication::setupGLView();
        
        // Это число — твой новый FPS
        float targetFPS = 240.0f; 
        
        CCDirector::sharedDirector()->setAnimationInterval(1.0f / targetFPS);
    }
};
 main
