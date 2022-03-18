#include "player.h"
#include "settings.h"
Player::Player() {
	texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.28f);
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	sprite.setPosition( WINDOW_WIDTH/13, WINDOW_HEIGHT / 1.3 - g_bounds.height);
}
void Player::update() {
	sf::Vector2f position = sprite.getPosition();
	
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))  sprite.move(0.f, -PLAYER_SPEED);
	if (position.y == WINDOW_HEIGHT / 2) { sprite.move(0.f, +PLAYER_SPEED); }
}
void Player::draw(sf::RenderWindow& window) { window.draw(sprite); }
sf::FloatRect Player::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Player::getPosition() { return sprite.getPosition(); }
