#pragma once
#include "BaseComponent.h"
#include <Windows.h>
#include <DirectXMath.h>

class TransformComponent : public BaseComponent {
public:
	DirectX::XMMATRIX model;
	DirectX::XMMATRIX positionM;
	DirectX::XMMATRIX rotationM;
	DirectX::XMMATRIX scaleM;

	TransformComponent();
	TransformComponent(DirectX::XMMATRIX xm);
	void Translate(DirectX::XMMATRIX xm);
	void Rotate(DirectX::XMMATRIX xm);
	void Scale(float scale);
	void Update();
};
