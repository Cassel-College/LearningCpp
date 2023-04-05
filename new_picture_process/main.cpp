#include <iostream>
#include <fstream>
#include <vector>
#include "stdlib.h"
#include "stdio.h"
#include <cstdlib> 
#include <string>
#include <map>
#include <algorithm>
#include <memory>

#include "src/cases/cases_001/running_001.h"
#include "src/cases/cases_002/running_002.h"
#include "src/cases/cases_003/running_003.h"
#include "src/cases/cases_004/running_004.h"
#include "src/cases/cases_005/running_005.h"
#include "src/cases/cases_006/running_006.h"
#include "src/cases/cases_007/running_007.h"
#include "src/cases/cases_008/running_008.h"
#include "src/cases/cases_009/running_009.h"
#include "src/cases/cases_010/running_010.h"

int main()
{
	std::shared_ptr<Exec001> execution_001 = std::make_shared<Exec001>();
	execution_001->run();

	std::shared_ptr<Exec002> execution_002 = std::make_shared<Exec002>();
	execution_002->run();

	std::shared_ptr<Exec003> execution_003 = std::make_shared<Exec003>();
	execution_003->run();

	std::shared_ptr<Exec004> execution_004 = std::make_shared<Exec004>();
	execution_004->run();

	std::shared_ptr<Exec005> execution_005 = std::make_shared<Exec005>();
	execution_005->run();

	std::shared_ptr<Exec006> execution_006 = std::make_shared<Exec006>();
	execution_006->run();

	std::shared_ptr<Exec007> execution_007 = std::make_shared<Exec007>();
	execution_007->run();

	std::shared_ptr<Exec008> execution_008 = std::make_shared<Exec008>();
	execution_008->run();

	std::shared_ptr<Exec009> execution_009 = std::make_shared<Exec009>();
	execution_009->run();

	std::shared_ptr<Exec010> execution_010 = std::make_shared<Exec010>();
	execution_010->run();

	return 0;
}