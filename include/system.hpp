#pragma once

class System {
  public:
  virtual ~System() = default;

  virtual void Init() = 0;
  
  virtual void Update() = 0;
  
  virtual void End() = 0; 
};