#include "..\\pch.h"

#include "Key.h"


Key & Key::GetInstance()
{
	static Key* instance = new Key();
	if (instance == nullptr)
	{
		instance = new Key();
	}

	return *instance;
}

void Key::Update()
{
	// キー入力情報を取得
	DirectX::Keyboard::State key = keyboard->GetState();
	keyTracker->Update(key);

}

Key::Key()
{
	keyboard = std::make_unique<DirectX::Keyboard>();
	keyTracker = std::make_unique<DirectX::Keyboard::KeyboardStateTracker>();
}


