#include "const.h"
#include "shield.h"
#include "player.h"

Shield::Shield () {
	texture.loadFromFile(IMAGES_FOLDER + SHIELD_FILE_NAME);
	sprite.setTexture(texture);
	sprite.setPosition(0.f, WINDOW_HEIGHT + getHeight()); // ��� ����
	//sprite.setOrigin(getWidth() / 2.0, getHeight() / 2.0); // ����� ���� ���������� �� ����� �������
}
void Shield::draw(sf::RenderWindow& window) {
	window.draw(sprite); 
}
void Shield::update(sf::Vector2f position) { 
	if (visible) { 
		sprite.setPosition(position.x - 15, position.y - 25); 
	}
	else {		
		sprite.setPosition(0.f, WINDOW_HEIGHT + getHeight()); // ��� ����
	}
	//sprite.setOrigin(getWidth() / 2.0, getHeight());
}

size_t Shield::getWidth() { return sprite.getLocalBounds().width; }
size_t Shield::getHeight() { return sprite.getLocalBounds().height; }
sf::FloatRect Shield::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Shield::getPosition() { return sprite.getPosition(); }
//void Shield::setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }	// ���������� ����� ���� �� ����� �������, ��������� position
void Shield::setPosition(sf::Vector2f pos) { sprite.getPosition().x + getWidth() / 4.0, sprite.getPosition().y + getHeight() / 4.0; }
/*sf::Vector2f Shield::getCenter() {
	return sf::Vector2f
	(
		sprite.getPosition().x + getWidth() / 2.0,
		sprite.getPosition().y + getHeight() / 2.0
	);
}*/

bool Shield::getDel() { return del; }
void Shield::setDel(bool x) { del = x; }
bool Shield::getVisible() { return visible; }
void Shield::setVisible(bool x) { visible = x; }