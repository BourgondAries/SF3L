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

#ifndef VERTEX_HPP_INCLUDED
#define VERTEX_HPP_INCLUDED

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

// Program specific:
#include "Movable.hpp"
#include "Colorable.hpp"
#include "Color.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:


namespace sf3
{
    ////////////////////////////////////////////////////////////
    /// \brief A single, colored point in space.
    ///
    ////////////////////////////////////////////////////////////
    class Vertex
    :
    public Movable,
    public Colorable,
    public sf::Drawable
    {
    public:

        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// \param position     Position of the vertex, standard null
        /// \param color        Color of the vertex, standard white
        ///
        ////////////////////////////////////////////////////////////
        Vertex
        (
            sf::Vector3f position = sf::Vector3f(0.f, 0.f, 0.f),
            sf::Color color = sf::Color(255, 255, 255)
        );

        ////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param vertex     Vertex to copy data from
        ///
        ////////////////////////////////////////////////////////////
        Vertex(const Vertex &vertex);

        ////////////////////////////////////////////////////////////
        /// \brief Assignment operator
        ///
        /// \param vertex     Vertex to copy data from
        ///
        ////////////////////////////////////////////////////////////
        void operator=(const Vertex &vertex);

        ////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param vertex     Vertex to copy data from
        ///
        ////////////////////////////////////////////////////////////
        ~Vertex();

        ////////////////////////////////////////////////////////////
        /// \brief Change the color
        ///
        /// \param color     sf::Color to assign the vertex
        ///
        ////////////////////////////////////////////////////////////
        virtual void setColor(const sf::Color &color) final override;

        ////////////////////////////////////////////////////////////
        /// \brief Change the color
        ///
        /// \param color     Color to assign the vertex
        ///
        ////////////////////////////////////////////////////////////
        virtual void setColor(const Color &color) final override;

        ////////////////////////////////////////////////////////////
        /// \brief Fetch the color of the vertex
        ///
        /// \return Current color of the vertex
        ///
        ////////////////////////////////////////////////////////////
        virtual const Color &getColor() const final override;

        ////////////////////////////////////////////////////////////
        /// \brief Move the vertex
        ///
        /// Essentially the same as vertex.setPosition(vertex.getPosition() + sf::Vector3f(...));
        ///
        /// \param offset     The value to add to the current position.
        ///
        ////////////////////////////////////////////////////////////
        virtual void move(const sf::Vector3f &offset) final override;

        ////////////////////////////////////////////////////////////
        /// \brief Set the position
        ///
        /// \param offset     Position to assign to the vertex
        ///
        ////////////////////////////////////////////////////////////
        virtual void setPosition(const sf::Vector3f &offset) final override;

    private:

        ////////////////////////////////////////////////////////////
        /// \brief Draw to the specified target
        ///
        /// \param target       Target to draw to, texture or screen
        /// \param states       The state of the rendering context
        ///
        ////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const final override;

        ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        sf3::Color m_color; ///< Color of the vertex
        GLuint m_displist; ///< Nested display list for fast drawing
        static constexpr std::size_t cm_display_list_amount = 2; ///< Amount of display lists needed
        static constexpr GLuint cm_position = 0, cm_color = 1; ///< Display list offsets

        friend class Triangle;
        friend class Rectangle;
        friend class Polygon;
        friend class Sprite;
        friend class Square;
    };

} // Namespace sf3


#endif // VERTEX_HPP_INCLUDED
