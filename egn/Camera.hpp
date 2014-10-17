#ifndef EGN_CAMERA_HPP
#define EGN_CAMERA_HPP

#include "Util.hpp"

namespace egn {

class Camera
{
		friend class Window;

	public:
		Camera( egn::FloatRect position );
		Camera();
		~Camera();

		/* redimention camera */
		void resize( egn::FloatRect position );

		/* déplacer la camera */
		void move( float x, float y );

		/* déterminer les limites de positionnement de la camera */
		void setLimit( egn::FloatRect position );

		/* centrer un point */
		void setFocus( egn::Vector2f focus );

		void copy( egn::Camera& camera );

		void actualize();

		egn::FloatRect getPosition() const;

	private:
		void setRenderWindowPtr( sf::RenderWindow* render );
		void adjust();

	private:
		sf::RenderWindow* m_RenderWindowPtr;
		sf::View m_View;

		egn::FloatRect m_Limit;
		egn::FloatRect m_Position;
};

} // namespace egn

#endif // EGN_CAMERA_HPP
