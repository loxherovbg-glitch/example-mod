#include <Geode/Geode.hpp>
#include <Geode/modify/CCApplication.hpp>

using namespace geode::prelude;

class $modify(CCApplication) {
    void setupGLView() {
        CCApplication::setupGLView();
        
        // Это число — твой новый FPS
        float targetFPS = 240.0f; 
        
        CCDirector::sharedDirector()->setAnimationInterval(1.0f / targetFPS);
    }
};
