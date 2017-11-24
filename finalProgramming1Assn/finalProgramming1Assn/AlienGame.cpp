//Alien Cannon Fodder
#include <iostream>
#include <sstream>
using namespace std;
#include <SFML/Graphics.hpp>

// utility functions
string numToString(int num);
sf::RectangleShape createCannon(float length, float width, float bottomX, float bottomY);
sf::RectangleShape createGround(float groundX, float groundY, float length);
sf::Text createText(sf::Font font);
sf::Font createFont();
sf::CircleShape createCannonball(float radius, float x, float y);
float getRadians(float);
void setTextAttributes(sf::Text & text, sf::Font & font);

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float GROUND_Y = WINDOW_HEIGHT - 50;
const float CANNON_LEN = 100;
const float CANNON_WIDTH = 5;
const float CANNON_BASE_X = 50;
const float CANNON_BASE_Y = GROUND_Y;
const float TARGET_LEN = 100;
const float TARGET_WIDTH = 50;
const float TARGET_BASE_X = 600;
const float TARGET_BASE_Y = 500;

int main()
{
	// cannon, ground, and text objects
	sf::RectangleShape cannon, ground;
	sf::RectangleShape target;
	sf::CircleShape cannonball;
	sf::Font font;
	sf::Text text;


	float cannonAngle = -45;	// current angle of cannon (note: upside down)
	float GRAVITY = 9.8f;		// gravitational constant
	float targetSpeed = 1.0f;// moves the target at the appropriate speed
	float angleRadians;//cos and sin functions require this conversion
	float time = 0;// might need to add these two things to a firecannonball function
	float speed = 80;//used to calculate velocity
	bool inFlight = false;//bool that tells game whether or not ball is in flight
	int hit = 0;//counter for number of hits
	float canTipX;
	float canTipY;
	float ballX, ballY;
	float velocityX, velocityY;
	float cannonFiredX;
	float cannonFiredY;


	// create window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cannon!");
	window.setFramerateLimit(60);

	// create cannon, ground, and text objects
	cannon = createCannon(CANNON_LEN, CANNON_WIDTH, CANNON_BASE_X, CANNON_BASE_Y);
	ground = createGround(0, GROUND_Y, (float)WINDOW_WIDTH);
	font = createFont();
	setTextAttributes(text, font);

	//create a target
	target = createCannon(TARGET_LEN, TARGET_WIDTH, TARGET_BASE_X, TARGET_BASE_Y);
	target.setFillColor(sf::Color::Blue);

	//=================================================================
	// main event loop
	//=================================================================
	while (window.isOpen())
	{
		// don't mess with this event loop; leave as is
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window
		window.clear(sf::Color::White);

		// draw the ground
		window.draw(ground);

		//if up or down arrows are pressed (FUNCTION?)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			cannonAngle -= 1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			cannonAngle += 1;
		if (cannonAngle < -90)
			cannonAngle = -90;
		else if (cannonAngle == 0)
			cannonAngle = -1;

		// set angle of cannon and draw it
		cannon.setRotation(cannonAngle);
		window.draw(cannon);

		//find cannonball start location (REARRANGE)
		angleRadians = getRadians(cannonAngle);

		//checking for flight and key(FUNCTION)
		if (!inFlight && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//calculate physics
			canTipX = CANNON_BASE_X + (CANNON_LEN * cos(angleRadians));
			canTipY = CANNON_BASE_Y + (CANNON_LEN * sin(angleRadians));
			velocityX = speed * cos(angleRadians);
			velocityY = speed * sin(-angleRadians);//had to flip sign here to make it work
			//create a cannonball
			inFlight = true;
			cannonball = createCannonball(5, canTipX, canTipY);
			cannonFiredX = canTipX;
			cannonFiredY = canTipY;
			time = 0;
		}
		//draw ball based on flag (in the air!) (take snapshot of where ball started in reference to cannon tip in different variables)
		if (inFlight)
		{
			//preserve values for ball when cannon was fired. I thought the cannon was supposed to draw the ball based on these positions
			ballX = velocityX * time + cannonFiredX;
			ballY = cannonFiredY - (velocityY * time) + (.5 * GRAVITY * (time * time));
			cannonball.setPosition(ballX, ballY);
			window.draw(cannonball);
			time += .1;
		}
		//change flag if out of bounds
		if (ballY >= GROUND_Y || ballX > WINDOW_WIDTH || time == 20)
		{
			inFlight = false;
		}

		//check if ball hit the target
		if (inFlight && target.getGlobalBounds().intersects(cannonball.getGlobalBounds()))
		{
			inFlight = false;
			hit++;//currently counter goes up without bounds
		}

		// show some text
		text.setString("Hit: " + numToString(hit));
		window.draw(text);

		//move target
		if (target.getPosition().x + TARGET_WIDTH > WINDOW_WIDTH - 50 || target.getPosition().x < 600)
			targetSpeed *= -1;
		target.move(targetSpeed, 0);

		//draw target
		window.draw(target);

		// end the current frame; put everything on the screen
		window.display();
	}

	return 0;
}

// convert an integer to a string. This uses some magic we haven't discussed;
// don't worry about understanding it for now.
string numToString(int num)
{
	std::ostringstream ss; //string buffer to convert numbers to string
	ss << num;
	return ss.str();
}

// return an initialized cannon
sf::RectangleShape createCannon(float length, float width, float bottomX, float bottomY)
{
	sf::RectangleShape cannon(sf::Vector2f(length, width));
	cannon.setFillColor(sf::Color::Black);
	cannon.setPosition(bottomX, bottomY);
	return cannon;
}

sf::CircleShape createCannonball(float radius, float x, float y)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(1);
	circle.setPosition(x, y);

	return circle;
}

// return a rectangle to use for ground
sf::RectangleShape createGround(float groundX, float groundY, float length)
{
	sf::RectangleShape ground(sf::Vector2f(length, 5.0f));
	ground.setFillColor(sf::Color::Green);
	ground.setPosition(groundX, groundY);
	return ground;
}

// return a text object with specified font attached
sf::Text createText(sf::Font font)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24); // in pixels, not points!
	text.setColor(sf::Color::Red);
	text.setPosition(20, 20);
	return text;
}

// If you want a different font, you'll have to copy it into
// project folder
sf::Font createFont()
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "can't load font" << endl;
		exit(0);
	}
	return font;
}

// set text attributes
void setTextAttributes(sf::Text & text, sf::Font & font)
{
	text.setFont(font);
	text.setCharacterSize(24); // in pixels, not points!
	text.setColor(sf::Color::Red);
	text.setPosition(20, 20);
}

float getRadians(float cannonAngle)
{
	float radianAngle;

	radianAngle = cannonAngle * (3.1419 / 180);

	return radianAngle;
}