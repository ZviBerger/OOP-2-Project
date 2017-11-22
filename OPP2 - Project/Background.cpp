#include "Background.h"

//V2f operator+(V2f a, V2f b) { return{ a.x + b.x, a.y + b.y }; };
//V2f operator+=(V2f a, V2f b) { return a + b; };
//V2f operator*(V2f a,V2f b) { return{ a.x * b.x, a.y * b.y }; };
//V2f operator-(V2f a, V2f b) { return a + V2f{ -1,-1 }*b; };
//V2f operator/(V2f a, V2f b) { return{ a.x / b.x, a.y / b.y }; };

Background::Background()
	:m_mainBG(windowSize),m_mainBGP(V2f{0,0}),m_factor(V2f{0,0}),m_moved(false)
{
	static  std::vector<sf::Texture> txt (5);
	static bool loaded = false;
	if (!loaded)
	{
		loaded = txt[0].loadFromFile(path2image::backGround) && 
			txt[1].loadFromFile(path2image::bg1) &&
			txt[2].loadFromFile(path2image::bg2)/*&&
			txt[3].loadFromFile(path2image::bg3) && 
			txt[4].loadFromFile(path2image::bg4)*/ ;
		if (!loaded)
			throw MyExeption{ "didn't load the pictures. please make sure it's in the folder." };
	}
	
	m_mainBG.setTexture(&txt[0]);
	m_mainBG.setOutlineColor(sf::Color::Yellow);
	m_mainBG.setOutlineThickness(5);
	//adding all layer to vector
	for (int i = 0; i < 1; i++)//change to wanted amount
		m_layers.push_back(layer{ txt[i + 1],windowSize,m_mainBGP, 200 / float(i+1) });
		
	

	//m_layers[0]._bg1.setFillColor(sf::Color::Yellow);
	//m_layers[0]._bg2.setFillColor(sf::Color::Yellow);
	//m_layers[1]._bg1.setFillColor(sf::Color::Red);
	//m_layers[1]._bg2.setFillColor(sf::Color::Red);


	/*auto getRandomColor = [&]() {
		using namespace sf;
		static const std::vector<Color> colors{ Color::Yellow,Color::Blue,Color::Cyan,Color::Green,Color::Magenta,Color::Red };
		return colors[rand() % colors.size()];

	};*/
	
	
}


Background::~Background()
{
}


void Background::draw(sf::RenderWindow & window)
{
	updateMove();
	window.draw(m_mainBG);
	/*for (auto &l : m_layers)
		l.draw(window);*/
}

void Background::updateMove()
{
	m_mainBG.setPosition(m_mainBGP);
	if (m_moved) 
	{
		for (auto &l : m_layers)
			l.move(m_direction, m_factor, m_mainBG.getGlobalBounds());
	}
	
}

void Background::setPosition(const V2f &p)
{
	/*for (auto pos : m_layers)
		pos.second.y += (m_mainBGP.y - p.y);*/
	findNextDir(p);
	m_mainBGP = p;

}

void Background::findNextDir(const V2f & newPos)
{
	
	m_moved = (newPos.x != m_mainBGP.x);
	m_direction = newPos.x >= m_mainBGP.x ? RIGHT : LEFT;
    m_factor =  newPos - m_mainBGP;
	
}

