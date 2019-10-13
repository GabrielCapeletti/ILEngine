#pragma once

namespace ILEngine
{
	class ILRenderer
	{
	public:		
		virtual void Update() = 0;
		virtual void Render() = 0;
	};
}