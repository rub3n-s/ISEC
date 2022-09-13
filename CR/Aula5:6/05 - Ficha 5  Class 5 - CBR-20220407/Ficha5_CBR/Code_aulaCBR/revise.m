function [journey, new_case] = revise(retrieved_cases, new_case, new_price)
    
    retrieved_codes = retrieved_cases{:,1};
    code = str2double('-');
        
    while isnan(code) || fix(code) ~= code || ismember(code, retrieved_codes) == 0
        fprintf('From the retrieved cases, which is the one that better matches your journey?\n');
        code = str2double(input('Journey Code: ','s'));
    end
    
    journey = fix(code);
    
    %       price
    fprintf('\nUpdate your journey price with the new estimated value? (y/n)\n');
    option = input('Option: ', 's');

    if option == 'y' || option == 'Y'
        new_case.price = new_price;
    end

    %       holiday type
    fprintf('\nUpdate the Holiday Type? (y/n)\n');
    option = input('Option: ', 's');

    if option == 'y' || 'Y'
        holiday_type = input('Active, Bathing, Cit, Education, Language, Recreation, Skiing, Wandering: ','s');
        new_case.holiday_type = holiday_type;
    end

    fprintf('\nUpdate the number of people? (y/n)\n');
    option = input('Option: ', 's');

    if option == 'y' || 'Y'
        number_persons = str2double('Number of Persons: ','s');
        new_case.number_persons = number_persons;
    end

    %       region
    fprintf('\nUpdate the region? (y/n)\n');
    option = input('Option: ', 's');

    if option == 'y' || 'Y'
        region = input('Region: ','s');
        new_case.region = region;
    end

    %       transportation
    fprintf('\nUpdate the transportation? (y/n)\n');
    option = input('Option: ', 's');

    if option == 'y' || 'Y'
        transportation = input('Car, Coach, Plane or Train: ','s');
        new_case.transportation = transportation;
    end

    %       season
    fprintf('\nUpdate the season? (y/n)\n');
    option = input('Option: ', 's');

    if option == 'y' || 'Y'
        season = input('Season: ','s');
        new_case.season = season;
    end

    %       accommodation
    fprintf('\nUpdate the accommodation? (y/n)\n');
    option = input('Option: ', 's');

    if option == 'y' || 'Y'
        accomodation = input('HolidayFlat, OneStart, TwoStart, ThreeStars, FourStars ou FiveStars: ','s');
        new_case.accomodation = accomodation;
    end
end

