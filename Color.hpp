////////////////////////////////////////////////////////////
//
// SF3L - Simple, Fast 3D Library
// Copyright © 2013 Kevin R. Stravers (macocio@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef COLOR_HPP_INCLUDED
#define COLOR_HPP_INCLUDED

// Program specific:

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp> // For sf::Color

// System specific includes:

namespace sf3
{

    struct Color
    {
        Color();
        Color(const float red, const float green, const float blue, const float alpha = 1.f);
        Color(const sf::Color &color);
        Color(const Color &color);
        ~Color();

        void operator=(const sf::Color &color);
        void operator=(const Color &color);

        float r, g, b, a;
    };

} // Namespace sf3

#endif // COLOR_HPP_INCLUDED
