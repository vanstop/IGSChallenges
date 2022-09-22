#include "ColorInterpolator.h"

int main() {
	uint32_t initialColor = 0x00001A;
	uint32_t finalColor = 0xFF001A;
	int steps = 3;

	vector<uint32_t> intermediateColors = InterpolateColors(initialColor, finalColor, steps);

	cout << uppercase << hex;

	cout << "Initial color: 0x" << initialColor << endl << endl;

	for (size_t i = 0; i < intermediateColors.size(); i++)
	{
		cout << "Color on step: " << i + 1 << " 0x" << intermediateColors[i] << endl;
	}

	cout << endl << "Final color: 0x" << finalColor << endl;

	return 0;
}

vector<uint32_t> InterpolateColors(uint32_t initialColor, uint32_t finalColor, int steps)
{
	uint32_t diference = finalColor - initialColor;
	uint32_t stepColor = diference / steps;

	vector<uint32_t> intermediateColors;

	for (size_t i = 1; i <= steps; i++)
	{
		intermediateColors.push_back(initialColor + (stepColor * i));
	}

	return intermediateColors;
}
