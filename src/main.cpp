#include <Geode/Geode.hpp>
#include <Geode/modify/CCApplication.hpp>

using namespace geode::prelude;

// Эта функция меняет FPS
void updateCustomFPS() {
    auto fpsValue = Mod::get()->getSettingValue<double>("fps-limit");
    auto enabled = Mod::get()->getSettingValue<bool>("enable-bypass");

    if (enabled) {
        CCDirector::sharedDirector()->setAnimationInterval(1.0 / fpsValue);
    } else {
        // Возвращаем стандарт (обычно 60)
        CCDirector::sharedDirector()->setAnimationInterval(1.0 / 60.0);
    }
}

class $modify(CCApplication) {
    void setupGLView() {
        CCApplication::setupGLView();
        updateCustomFPS();
    }
};

// Слушаем изменения в настройках прямо в игре
$execute {
    listenForSettingChanges("enable-bypass", [](bool) {
        updateCustomFPS();
    });
    listenForSettingChanges("fps-limit", [](double) {
        updateCustomFPS();
    });
}
