/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
protected:
	PiezasTest() {}			   //constructor runs before each test
	virtual ~PiezasTest() {}   //destructor cleans up after tests
	virtual void SetUp() {}	   //sets up before each test (after constructor)
	virtual void TearDown() {} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, constructor)
{
	Piezas game;
	bool empty = true;
	for (int i = 0; i < BOARD_ROWS; i++)
	{
		for (int j = 0; j < BOARD_COLS; j++)
		{
			if (game.pieceAt(i, j) != Blank)
				empty = false;
		}
	}
	ASSERT_TRUE(empty);
}

TEST(PiezasTest, reset)
{
	Piezas game;
	game.dropPiece(0);
	game.reset();
	bool empty = true;
	for (int i = 0; i < BOARD_ROWS; i++)
	{
		for (int j = 0; j < BOARD_COLS; j++)
		{
			if (game.pieceAt(i, j) != Blank)
				empty = false;
		}
	}
	ASSERT_TRUE(empty);
}

TEST(PiezasTest, dropPiece)
{
	Piezas game;
	Piece p = game.dropPiece(0);
	ASSERT_EQ(p, X);
}
TEST(PiezasTest, dropPiece2)
{
	Piezas game;
	Piece p = game.dropPiece(0);
	p = game.dropPiece(0);
	ASSERT_EQ(p, O);
}
TEST(PiezasTest, dropPieceFullColInvalid)
{
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	Piece p = game.dropPiece(0);
	ASSERT_EQ(p, Blank);
}

TEST(PiezasTest, dropPieceOutOfBounds)
{
	Piezas game;
	Piece p = game.dropPiece(10);
	ASSERT_EQ(p, Invalid);
}

TEST(PiezasTest, dropPieceFullCol)
{
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	Piece p = game.pieceAt(0, 0);
	ASSERT_EQ(p, X);
}

TEST(PiezasTest, pieceAtUnhappy)
{
	Piezas game;
	Piece p = game.pieceAt(10, 0);
	ASSERT_EQ(p, Invalid);
}
TEST(PiezasTest, pieceAt)
{
	Piezas game;
	game.dropPiece(0);
	Piece p = game.pieceAt(2, 0);
	ASSERT_EQ(p, X);
}

TEST(PiezasTest, BlankBoard)
{
	Piezas game;
	ASSERT_EQ(game.gameState(), Invalid);
}

TEST(PiezasTest, noWinner)
{
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);
	ASSERT_EQ(game.gameState(), Blank);
}

TEST(PiezasTest, xWins)
{
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(1);
	ASSERT_EQ(game.gameState(), X);
}

TEST(PiezasTest, yWins)
{
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	ASSERT_EQ(game.gameState(), O);
}