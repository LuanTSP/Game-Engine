#pragma once
#include "system.hpp"
#include "utils.hpp"
#include <SFML/Graphics.hpp>

class RenderSystem : public System {
public:
  using System::System;

  void update(float elapsed) override;
};
