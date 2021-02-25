#include <iostream>

#include <memory>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>


void indexing(Fl_Widget *, void *) 
{
	std::cout << "clicked!" << std::endl;
	std::vector<int> testVector;
	testVector.resize( 0 );
	int x = testVector.at( 0 );
}

void zeroDivision( Fl_Widget *, void * )
{
	std::cout << "clicked!" << std::endl;
	float x = 1 / 0;
}


int main(int argc, char **argv)
{

	std::cout << "Coredump generator program" << std::endl;

	std::unique_ptr<Fl_Window> window = std::make_unique<Fl_Window>( 340, 500 );
	std::unique_ptr<Fl_Button> button = std::make_unique<Fl_Button>(20,40,300,100,"&Click!");
	std::unique_ptr<Fl_Button> button_2 = std::make_unique<Fl_Button>(20,160,300,100,"&Click 2!");


	button->box(FL_UP_BOX);
	button->labelfont(FL_BOLD+FL_ITALIC);
	button->labelsize(36);
	button->labeltype(FL_SHADOW_LABEL);
	button->callback( indexing );

	button_2->box(FL_UP_BOX);
	button_2->labelfont(FL_BOLD+FL_ITALIC);
	button_2->labelsize(36);
	button_2->labeltype(FL_SHADOW_LABEL);
	button_2->callback( zeroDivision );


	window->end();
	window->show(argc, argv);

	
	return Fl::run();

}