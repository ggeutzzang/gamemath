#pragma once

namespace CK
{

struct HSVColor
{
public:
	FORCEINLINE constexpr HSVColor() = default;
    FORCEINLINE constexpr HSVColor(float InH, float InS, float InV) : H(InH), S(InS), V(InV) {}
    
    // HSV 색상 체계를 RGB 색상 체계로 변환하는 함수
    FORCEINLINE constexpr LinearColor ToLinearColor() const
	{
        float r = 0.f, g = 0.f, b = 0.f;

        int i = Math::FloorToInt(H * 6.f);
        float f = H * 6.f - i;
        float p = V * (1.f - S);
        float q = V * (1 - f * S);
        float t = V * (1 - (1 - f) * S);

        switch (i % 6) {
        case 0: r = V, g = t, b = p; break;
        case 1: r = q, g = V, b = p; break;
        case 2: r = p, g = V, b = t; break;
        case 3: r = p, g = q, b = V; break;
        case 4: r = t, g = p, b = V; break;
        case 5: r = V, g = p, b = q; break;
        }

        return LinearColor(r, g, b);
	}

public:
    // HSV 값을 관리하는 멤버 변수
	float H = 0.f;
	float S = 1.f;
	float V = 1.f;
};

}

