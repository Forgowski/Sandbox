#include"Header.h"




int main()
{
	int bombs;
	srand(time(0)); 
	setlocale(LC_ALL,"");
		cout << "Wprowad? liczbe min jak? chcesz na swojej planszy minimalna liczba to 5 maksymalna 90: ";
		cin >> bombs;
	int restart = 1;
		while (restart == 1)
		{
			restart = 0;

			srand(time(0));
			sf::RenderWindow W;
			////////////////////////////////////////////////////////  tworzenie okna
			W.create(sf::VideoMode(1000, 600, 32), "Okno");
			W.setActive(true);
			W.setKeyRepeatEnabled(false);
			W.setVerticalSyncEnabled(true);
			W.setPosition(sf::Vector2i(400, 350));
			////////////////////////////////////////////////////////


			int* map = new int[100]; //mapa
			prepare(map,bombs);


			vector<RectangleShape> V;
			for (int i = 0; i < 10; i++)
			{

				for (int j = 0; j < 10; j++)
				{
					V.push_back(RectangleShape(Vector2f(30, 30)));					//dodawanie pola
					V[i * 10 + j].setOrigin(0, 0);
					V[i * 10 + j].setFillColor(Color(0, 0, 255));
					V[i * 10 + j].setPosition(Vector2f(150 + (j * 30), 150 + (i * 30)));
					V[i * 10 + j].setOutlineThickness(1);
					V[i * 10 + j].setOutlineColor(Color(100, 100, 100));

				}
			}

			Font ttf;
			ttf.loadFromFile("txt.ttf");
			string s("");
			Text txt(s, ttf);


			vector <Text> H;
			Text H2(s, ttf), H3(s, ttf);
			H2.setCharacterSize(20);
			H2.setFillColor(Color(150, 100, 100));

			stringstream ss;
			sf::Event e;
			int end = 0, hmtw = 0;
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			while (W.isOpen())
			{
				if (end != 1) {

					while (W.pollEvent(e))
					{
						int x = 0;
						if (e.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))W.close();

						if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
						{
							for (auto r : V)
							{

								if (r.getGlobalBounds().contains(GetMousPosition(&W)))
								{

									if (check(x, map))
									{
										txt.setCharacterSize(35);
										txt.setFillColor(Color(255, 0, 0));
										txt.setPosition(150, 450);
										ss.str("GAME OVER PRESS ESC TO TURN OFF");
										txt.setString(ss.str());
										V[x].setFillColor(Color(200, 0, 0));
										end = 1;
									}
									else
									{

										ss.str("");
										if (howmany(x, map) == 0)
										{
											
											IfHowManyNull(x, map, V,H,H2);																																							
											
										}
										else 
										{
											ss << howmany(x, map);
											V[x].setFillColor(Color(255, 255, 255));
											H2.setString(ss.str());
											H2.setPosition(V[x].getPosition().x + 10, V[x].getPosition().y);
											H.push_back(H2);											
										}

										///////////////////////////////////////////////////////////////////////// sprawdzenie wygranej
										hmtw = 0;
										for (auto r : V)
										{
											if (r.getFillColor()==Color(255,255,255))hmtw++;
											{	
												if (hmtw == 100 - bombs)
												{
													txt.setCharacterSize(50);
														txt.setFillColor(Color(0, 100, 0));
														txt.setPosition(150, 450);
														ss.str("YOU WON GOOD JOB");
														txt.setString(ss.str());
														end = 1;
												}
											}
										}

									}
								}
								x++;
							}
						}
						if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Right)
						{
							
							
							for (auto r : V)
							{

								if (r.getGlobalBounds().contains(GetMousPosition(&W)))
								{	
									if (r.getFillColor()==Color(0,0,255))
									{
										V[x].setFillColor(Color(255, 100, 100));
									}
									if (r.getFillColor() == Color(255, 100, 100))
									{
										V[x].setFillColor(Color(0, 0, 255));
									}
								}
								x++;
							}
						}
						
					}
				}
				if (end == 1)
				{

					while (W.pollEvent(e))
					{
						int x = 0;
						for (auto r : V)
						{
							if (check(x, map))V[x].setFillColor(Color(200, 0, 0));
							else {
								howmany(x, map);
								ss.str("");
								ss << howmany(x, map);
								V[x].setFillColor(Color(255, 255, 255));
								H2.setString(ss.str());
								H2.setPosition(V[x].getPosition().x + 10, V[x].getPosition().y);
								H.push_back(H2);
							}
							x++;
							W.draw(r);

						}


						H3.setString("PRESS Q TO RESTART");
						H3.setFillColor(Color(255, 0, 0));
						H3.setPosition(500, 150);
						if (e.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))W.close();
						else if (e.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)))
						{
							restart = 1;
							W.close();
							
						}
					}
				}
				W.clear(sf::Color(0, 0, 0));
				W.draw(H3);
				for (auto r : V)
				{
					W.draw(r);
				}

				for (auto r : H)
				{
					W.draw(r);
				}

				W.draw(txt);
				W.display();
			}
			delete map;

			

		}
		return 0;
}
