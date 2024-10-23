function checkPixel()
      blueT = bluetooth('HC-05',1);
      bluetooth(blueT);
%#codegen
%Create raspi 
coder.extrinsic("imagesc")
coder.extrinsic("impixelinfo")
coder.extrinsic("WindowState")
coder.target("clear")
mypi= raspi();


% array an ouput
my_array =[];

while 1

    for ii = 1:10
        button = readDigitalPin(mypi,4);
    end
    while  button ~= 1
        close all
        for ii = 1:5
            % row1
            writeDigitalPin(mypi,14,1)
        end
        %turn on webcam and capture the whiteboard
        cam = webcam(mypi);
        rawImage = snapshot(cam) ; 
        figure
        imshow(rawImage);
        rawImage = impixelinfo;
%         grayImage = rgb2gray(rawImage);     
%%%%%%%%crop the whiteboard area from the entire image
        if size(rawImage,3) == 3
            bwImage = imquantize(rawImage,0.545500003);
        elseif size(rawImage,3) == 1
            bwImage = rawImage;
        else
            error('not a supported image')
        end

        mask = bwImage > 0.545500003;
        % segment the image, find the largest object
        S = regionprops(mask,'BoundingBox','Area');
        [MaxArea,MaxIndex] = max(vertcat(S.Area));
        rect = S(MaxIndex).BoundingBox;
        % Display the image; highlight the largest object

        figure(2)
        imshow(bwImage); hold on
        rectangle('Position',rect,'LineWidth',2,'EdgeColor','y')
        hold off
        % Extract a cropped image from the original.
        croppedImage = imcrop(rawImage,rect);
        % Display the cropped image.
        [rows, columns, numColorChannels] = size(croppedImage);
        figure
        imshow(croppedImage);
        axis on;
        impixelinfo
        
        numBandsVertically = 4;
        numBandsHorizontally = 3;
        topRows = round(linspace(1, rows+1, numBandsVertically + 1));
        leftColumns = round(linspace(1, columns+1, numBandsHorizontally + 1));


        plotCounter = 1;
        i=1;
      
        for row = 1 : length(topRows) - 1
            
	        row1 = topRows(row);
	        row2 = topRows(row + 1) - 1;
	        for col = 1 : length(leftColumns) - 1
		        col1 = leftColumns(col);
		        col2 = leftColumns(col + 1) - 1;
                
		        subplot(numBandsVertically, numBandsHorizontally, plotCounter);
		        subImage = croppedImage(row1 : row2, col1 : col2, :);
                bwImage = imquantize(subImage,0.4);
                imshow(bwImage);
                blackpixels = nnz(~bwImage);
                if any(blackpixels(:))
                my_array =[my_array,i];
                caption = sprintf('detected');
                title(caption);
                else
                
                end
                drawnow
		        plotCounter = plotCounter + 1;
                i = i+1;

	        end
        end      
        %fig.WindowState = 'maximized';
        
        clear cam
        button = readDigitalPin(mypi,4);

        fprintf('a: %d\n',my_array);
    end
    

end
    
end