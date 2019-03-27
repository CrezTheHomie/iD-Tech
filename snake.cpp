#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

using namespace std;

const float kSquareSize = 32.f; // 
const int kBoardWidthCells = 15; // Sets the width of the square the snake is in
const int kBoardHeightCells = 15; // Sets the height of the square the snake is in
const int kUpdatesPerTick = 10; // 

const unsigned kDeadSnakeHeadColor = 0xff0000ff;
const unsigned kLiveSnakeHeadColor = 0x00ff00ff;
const unsigned kBackgroundColor = 0x7f7f7fff;
const unsigned kSnakeBodyColor = 0x007f00ff;
const unsigned kFoodColor = 0xffff00ff;

class SnekGame
{
public:
	void run()
	{
		init();
		while (m_win.isOpen())
		{
			update();
			draw();
		}//while m win is open
	}

private:
	void init()
	{
		std::random_device rd;
		m_randomtwister.seed(rd());
		m_win.create(sf::VideoMode(800u, 600u), "Snek");
		auto v = m_win.getView();
		v.setCenter(kSquareSize * sf::Vector2f(kBoardWidthCells, kBoardHeightCells) / 2.f);
		m_win.setView(v);

		m_win.setFramerateLimit(60u);
		m_vertexarray.setPrimitiveType(sf::Quads);
		startGame();
	}

	void startGame()
	{
		m_head = sf::Vector2i(3, 3);
		m_body.assign(0, m_head);
		m_move = sf::Vector2i(1, 0);
		m_updatecounter = 0;
		m_gameover = false;
		m_win.setTitle("Snek");
		spawnFood();
	}

	void spawnFood()
	{
		while (true)
		{
			m_food.x = std::uniform_int_distribution<int>(0, kBoardWidthCells - 1)(m_randomtwister);
			m_food.y = std::uniform_int_distribution<int>(0, kBoardHeightCells - 1)(m_randomtwister);

			bool bad = false;
			if (m_head == m_food)
				bad = true;

			for (sf::Vector2i b : m_body)
				if (b == m_food)
					bad = true;

			if (!bad)
				return;
		}//while true
	}

	void update()
	{
		sf::Event eve;
		while (m_win.pollEvent(eve))
		{
			switch (eve.type)
			{
			case sf::Event::Closed:
				m_win.close();
				break;
			case sf::Event::KeyPressed:
				handleKeyPress(eve.key.code);
				break;
			case sf::Event::Resized:
			{
				auto v = m_win.getView();
				v.setSize(eve.size.width, eve.size.height);
				m_win.setView(v);
			}
			break;
			}//switch eve type
		}//while m win poll event eve

		if (m_gameover)
			return;

		++m_updatecounter;
		if (m_updatecounter < kUpdatesPerTick)
			return;

		m_updatecounter = 0;

		m_body.push_back(m_head);

		if (m_head == m_food)
			spawnFood();
		else
			m_body.erase(m_body.begin());

		m_head += m_move;

		if (m_head.x < 0 || m_head.y < 0 || m_head.x >= kBoardWidthCells || m_head.y >= kBoardHeightCells)
			m_gameover = true;

		for (sf::Vector2i b : m_body)
			if (b == m_head)
				m_gameover = true;

		if (m_gameover)
			m_win.setTitle("Snek - GAME OVER - Press F2 to reset");
	}

	void handleKeyPress(sf::Keyboard::Key key)
	{
		switch (key)
		{
		case sf::Keyboard::W:
			if (m_move.y == 0)
				m_move = sf::Vector2i(0, -1);
			break;
		case sf::Keyboard::S:
			if (m_move.y == 0)
				m_move = sf::Vector2i(0, 1);
			break;
		case sf::Keyboard::A:
			if (m_move.x == 0)
				m_move = sf::Vector2i(-1, 0);
			break;
		case sf::Keyboard::D:
			if (m_move.x == 0)
				m_move = sf::Vector2i(1, 0);
			break;
		case sf::Keyboard::F2:
			startGame();
			break;
		}//switch key
	}

	void draw()
	{
		if (!m_gameover)
			m_win.setTitle("Snek - " + std::to_string(m_body.size() + 1));

		m_win.clear();
		m_vertexarray.clear();

		addQuad(sf::Vector2f(), kSquareSize * sf::Vector2f(kBoardWidthCells, kBoardHeightCells), kBackgroundColor);
		for (sf::Vector2i b : m_body)
			addQuad(kSquareSize * sf::Vector2f(b), sf::Vector2f(kSquareSize, kSquareSize), kSnakeBodyColor);

		addQuad(kSquareSize * sf::Vector2f(m_food), sf::Vector2f(kSquareSize, kSquareSize), kFoodColor);
		const unsigned hcolor = m_gameover ? kDeadSnakeHeadColor : kLiveSnakeHeadColor;
		addQuad(kSquareSize * sf::Vector2f(m_head), sf::Vector2f(kSquareSize, kSquareSize), hcolor);

		m_win.draw(m_vertexarray);
		m_win.display();
	}

	void addQuad(sf::Vector2f pos, sf::Vector2f size, unsigned color)
	{
		m_vertexarray.append(sf::Vertex(pos, sf::Color(color)));
		m_vertexarray.append(sf::Vertex(pos + sf::Vector2f(0.f, size.y), sf::Color(color)));
		m_vertexarray.append(sf::Vertex(pos + size, sf::Color(color)));
		m_vertexarray.append(sf::Vertex(pos + sf::Vector2f(size.x, 0.f), sf::Color(color)));
	}

	sf::VertexArray m_vertexarray;
	sf::RenderWindow m_win;
	sf::Vector2i m_head;
	sf::Vector2i m_move;
	int m_updatecounter;
	bool m_gameover;
	std::vector<sf::Vector2i> m_body;
	sf::Vector2i m_food;
	std::mt19937 m_randomtwister;

};

int main(int argc, char ** argv)
{
	SnekGame game;
	game.run();
	return 0;
}