#include "MainComponent.h"
#include <iostream>
#include <fstream>

//==============================================================================
MainComponent::MainComponent()
{
    setSize (674, 641);
}

MainComponent::~MainComponent()
{
}
juce::Image loadImage(const juce::File& imf){
    
    if(!imf.existsAsFile()){
        DBG("File does not exist");
    }
    
    std::unique_ptr<juce::FileInputStream> inputStream(imf.createInputStream());
    juce::Image image = juce::ImageFileFormat::loadFrom(*inputStream);
    
    if (image.isNull())
        {
            DBG("Failed to load image");
        }

    return image;
}


//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    
    //reads in pic as absolute path
 //   juce::File imageFile("/Users/devwork/Desktop/Projects/plug1/plug1/Pic/scales.jpg");
    
    juce::File execFile = juce::File::getSpecialLocation(juce::File::currentExecutableFile);
    juce::File execDirectory = execFile.getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory();
    
    juce::File imageFile2 = execDirectory.getChildFile("Pic/scales.jpg");

 //   DBG(imageFile2.getFullPathName());
    
    juce::Image i = loadImage(imageFile2);
    
    
    
    
    
    
    
    g.drawImageAt(i, 0, 0);
   // g.drawText ("First Plug LESSGO", getLocalBounds(), juce::Justification::centred, true);
}


void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
