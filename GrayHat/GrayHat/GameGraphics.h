#pragma once

#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <stdio.h>
#include "TerminalGraphics_win.h"
#include "FileSystemFolder.h"
#include "FileSystemFile.h"
#include "Logger.h"

class GameGraphics
{
	public:

		GameGraphics();
		~GameGraphics();

		void init();

		void addProgram(std::string program);
		void setProgramPercent(std::string program, int percent);
		void setInputBuffer(std::string text);
		void addBufferHistory(std::string text);
		void setCurrentFolder(FileSystemFolder * folder);

		void render();
		void run();

	private:

		//logger
		Logger logger;

		std::vector<std::string> curProgNames;
		std::vector<int> curProgPercent;

		char bufferText[40];
		//std::string bufferText;
		std::vector<std::string> bufferHistory;

		FileSystemFolder * curFolder;

		TerminalGraphics_win graphics;

		std::thread renderer;
		bool running = true, editing = true;

		int SCRN_WIDTH = 1000;
		int SCRN_HEIGHT = 600;
		int CHAR_WIDTH = 120;
		int CHAR_HEIGHT = 36;

		int curProgRow = 0;
		int curProgPercentCol = (CHAR_WIDTH / 2) - 6;
		int curBufferRow = CHAR_HEIGHT - 1;
		int bufferHistoryRow = curBufferRow - 1;
		int maxBufferHistLines = 5;

		// render helper functions
		void drawPartitionLine();
		void drawRunningProgs();
		void drawBufferText();
		void drawBufferHist();
		void drawCurrentFolder();
};

