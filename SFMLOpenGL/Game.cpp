#include <Game.h>
#include "MyMatrix3.h"
#include "MyVector3.h"

bool flip = false;
int current = 1;
double rotationX = 0;
double rotationY = 0;
double rotationZ = 0;
MyVector3 moving { 0, 0, 0 };
float scale = 1.0;


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

float vertices[] = { -1.0f,-1.0f,-7.0f, // triangle 1 : begin
					-1.0f,-1.0f, -5.0f,
					-1.0f, 1.0f, -5.0f, // triangle 1 : end
					1.0f, 1.0f,-7.0f, // triangle 2 : begin
					-1.0f,-1.0f,-7.0f,
					-1.0f, 1.0f,-7.0f, // triangle 2 : end
					1.0f,-1.0f, -5.0f,
					-1.0f,-1.0f,-7.0f,
					1.0f,-1.0f,-7.0f,//3
					1.0f, 1.0f,-7.0f,
					1.0f,-1.0f,-7.0f,
					-1.0f,-1.0f,-7.0f,//4
					-1.0f,-1.0f,-7.0f,
					-1.0f, 1.0f, -5.0f,
					-1.0f, 1.0f,-7.0f,//5
					1.0f,-1.0f, -5.0f,
					-1.0f,-1.0f, -5.0f,
					-1.0f,-1.0f,-7.0f,//6
					-1.0f, 1.0f, -5.0f,
					-1.0f,-1.0f, -5.0f,
					1.0f,-1.0f, -5.0f,
					1.0f, 1.0f, -5.0f,
					1.0f,-1.0f,-7.0f,
					1.0f, 1.0f,-7.0f,
					1.0f,-1.0f,-7.0f,
					1.0f, 1.0f, -5.0f,
					1.0f,-1.0f, -5.0f,
					1.0f, 1.0f, -5.0f,
					1.0f, 1.0f,-7.0f,
					-1.0f, 1.0f,-7.0f,
					1.0f, 1.0f, -5.0f,
					-1.0f, 1.0f,-7.0f,
					-1.0f, 1.0f, -5.0f,
					1.0f, 1.0f, -5.0f,
					-1.0f, 1.0f, -5.0f,
					1.0f,-1.0f, -5.0f };
float colors[] = { 1.0f,  0.0f,  0.0f,
					1.0f,  0.0f,  0.0f,
					1.0f,  0.0f,  0.0f,
					0.0f,  1.0f,  0.0f,
					0.0f,  1.0f,  0.0f,
					0.0f,  1.0f,  0.0f,
					0.0f,  0.0f,  1.0f,
					0.0f,  0.0f,  1.0f,
					0.0f,  0.0f,  1.0f,
					1.0f,  0.0f,  1.0f,
					1.0f,  0.0f,  1.0f,
					1.0f,  0.0f,  1.0f,
					0.0f,  1.0f,  1.0f,
					0.0f,  1.0f,  1.0f,
					0.0f,  1.0f,  1.0f,
					1.0f,  1.0f,  0.0f,
					1.0f,  1.0f,  0.0f,
					1.0f,  1.0f,  0.0f,
					1.0f,  1.0f,  1.0f,
					1.0f,  1.0f,  1.0f,
					1.0f,  1.0f,  1.0f,
					0.6f, 1.0f, 1.0f,
					0.6f, 1.0f, 1.0f,
					0.6f, 1.0f, 1.0f,
					1.0f,  0.6f,  1.0f,
					1.0f,  0.6f,  1.0f,
					1.0f,  0.6f,  1.0f,
					1.0f,  1.0f,  0.6f,
					1.0f,  1.0f,  0.6f,
					1.0f,  1.0f,  0.6f,
					0.6f,  1.0f,  0.6f,
					0.6f,  1.0f,  0.6f,
					0.6f,  1.0f,  0.6f,
					0.0f,  0.5f,  0.3f,
					0.0f,  0.5f,  0.3f,
					0.0f,  0.5f,  0.3f };

unsigned int vertex_index[36];



void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if (sf::Keyboard::Z == event.key.code)
			{
				rotationZ += 0.01;
				if (rotationZ > 360)
				{
					rotationZ -= 360.0;
				}
			}
			if (sf::Keyboard::Y == event.key.code)
			{
				rotationY += 0.01;
				if (rotationY > 360)
				{
					rotationY -= 360.0;
				}
			}
			if (sf::Keyboard::X == event.key.code)
			{
				rotationX += 0.01;
				if (rotationX > 360)
				{
					rotationX -= 360.0;
				}
			}
			if (sf::Keyboard::Down == event.key.code)
			{
				moving.y -= 0.01;
			}
			if (sf::Keyboard::Up == event.key.code)
			{
				moving.y += 0.01;
			}
			if (sf::Keyboard::Left == event.key.code)
			{
				moving.x -= 0.01;
			}
			if (sf::Keyboard::Right == event.key.code)
			{
				moving.x += 0.01;
			}
			if (sf::Keyboard::S == event.key.code)
			{
				scale -= 0.01;
			}
			if (sf::Keyboard::D == event.key.code)
			{
				scale += 0.01;
			}
			
		}
		
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	for (int i = 0; i < 36; i++)
	{
		vertex_index[i] = i;
	}
	for (int i = 0; i < 36; i+=3)
	{
		MyVector3 variable(vertices[i], vertices[i + 1], vertices[i + 2]);
	}
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	for (int i = 0; i < 36; i++)
	{
		MyVector3 vector{ vertices[i * 3], vertices[i * 3 + 1], vertices[i * 3 + 2] + 6 };
		vector = MyMatrix3::rotationY(rotationY) * vector;
		vector = MyMatrix3::rotationX(rotationX) * vector;
		vector = MyMatrix3::rotationZ(rotationZ) * vector;
		vector = MyMatrix3::scale(scale) * vector;
		vector += moving;
		vertices[i * 3] = vector.x;
		vertices[i * 3 + 1] = vector.y;
		vertices[i * 3 + 2] = vector.z - 6;
	}

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	glDrawArrays(GL_TRIANGLES, 0, 36);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

