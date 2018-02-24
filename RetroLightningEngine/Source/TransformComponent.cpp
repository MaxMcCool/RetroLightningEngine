#include "TransformComponent.h"

TransformComponent::TransformComponent() {
	model = DirectX::XMMatrixIdentity();
}

TransformComponent::TransformComponent(DirectX::XMMATRIX xm)
{
	model = xm;
}

void TransformComponent::Translate(DirectX::XMMATRIX xm)
{
	positionM = xm;
}

void TransformComponent::Rotate(DirectX::XMMATRIX xm)
{
	rotationM = xm;
}

void TransformComponent::Scale(float scale)
{
	scaleM = DirectX::XMMatrixIdentity() * scale;
}

void TransformComponent::Update()
{
	model = model * positionM * rotationM * scaleM;
}