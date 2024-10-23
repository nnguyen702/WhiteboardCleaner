function detachWB()
      blueT = bluetooth('HC-05',1);
      bluetooth(blueT);
% array an ouput
my_array =[];
        rawImage = imread("i1.png") ;
        figure(1)
        imshow(rawImage);
        grayImage = rgb2gray(rawImage);
        %brightness = mean(grayImage);
        %disp('Brightness %d/n',brightness);
%%%%%%%%crop the whiteboard area from the entire image
        if size(rawImage,3) == 3
            bwImage = im2bw(rawImage,0.7);
        elseif size(rawImage,3) == 1
            bwImage = rawImage;
        else
            error('not a supported image')
        end

        mask = bwImage > 0.8;
        % segment the image, find the largest object
        S = regionprops(mask,'BoundingBox','Area');
        [MaxArea,MaxIndex] = max(vertcat(S.Area));
        rect = S(MaxIndex).BoundingBox;
        % Display the image; highlight the largest object

        
        imshow(bwImage); hold on
        rectangle('Position',rect,'LineWidth',2,'EdgeColor','y')
        hold off
        % Extract a cropped image from the original.
        croppedImage = imcrop(rawImage,rect);
        % Display the cropped image.
        
        imshow(croppedImage);
        [rows, columns, numColorChannels] = size(croppedImage);
        figure(2)
        imshow(croppedImage);
        axis on;
        impixelinfo

        numBandsVertically = 1;%rows
        numBandsHorizontally = 2;%collums
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
                bwImage = im2bw(subImage,0.7);
                imshow(bwImage);
                blackpixels = nnz(~bwImage);
                if any(blackpixels(:))
                    my_array=[my_array,i]
                    caption = sprintf('detected');
                    title(caption);
                else
                
                end
                drawnow
		        plotCounter = plotCounter + 1;
                i = i+1;

            end
        
        end
        fprintf('a: %d\n',my_array);

      write(blueT,my_array);
     
end        