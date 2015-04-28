	/*#ifndef WINDOW_MGR_H
	#define WINDOW_MGR_H
	#include<vector>
	#include"Screen.h"
	class Window_mgr{
	public:
		using ScreenIndex=std::vector<Screen>::size_type;
		void clear(ScreenIndex);

	private :
		std::vector<Screen> screens{Screen(24,80,' ')};
};
#endif //WINDOW_MGR_H
*/
#ifndef WYSCREEN_MGR_H
#define WYSCREEN_MGR_H

#include <vector>
#include "wyscreen.h"
class wyScreen;
class wyScreen_mgr
{
public:
	  wyScreen_mgr();
    //! @attention  note this statement
    using ScreenIndex =std::vector<wyScreen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<wyScreen> wyScreens;
};
#endif // WYSCREEN_MGR_H