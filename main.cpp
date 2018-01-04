#include <iostream>
#include <unordered_map>
#include <fstream>
#include "world/entity/bot/Bot.h"
#include "world/entity/bot/Assembly.h"
#include "world/entity/bot/Assembler.h"


int main(){
	std::vector<uint8_t> out;
	std::ifstream in("../assembly.asm");
	if(in.is_open()){
		IOBots::Assembler::assemble(in, out);
		in.close();
		IOBots::Bot b(0x10000);
		b.loadProgram(out);
		while(!b.HF)
			b.tick();
		std::cout << b << std::endl;
		std::cout << b.CF << std::endl;
	}else{
		std::cout << "File not opened." << std::endl;
	}
	return 0;
}