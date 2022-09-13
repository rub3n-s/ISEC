function [retrieved_indexes, similarities, new_case] = retrieve(case_library, new_case, threshold)
   
% Case-Based Reasoning:
% Tem em comum com a redes neuronais a posse de base de dados,
% porém nao tem fase de treinos como nas redes neuronais

% a) Preencha os pesos de cada atributo no vetor weighting_factor,
% assumindo que os atributos Price e Season são os mais relevantes no
% cálculo da semelhança
    weighting_factors = [
        0.1 % Holiday Type
        0.2 % Price
        0.1 % NumberOfPersons
        0.1 % Region
        0.1 % Transportation
        0.1 % Duration
        0.1 % Season
        0.1 % Accommodation
    ];

    holiday_type_sim = get_holiday_type_similarities();
    transportation_sim = get_transportation_similarities();
    accommodation_sim = get_accommodation_similarities();
    
    max_values = get_max_values(case_library);
    
    load('regions');
    [lat, lon] = get_lat_lon_from_google(new_case.region);
    new_case_latlon = [lat lon];
    new_case.latlon = [lat lon];
    
    retrieved_indexes = [];
    similarities = [];
    
    for i=1:size(case_library,1)
        
        distances = zeros(1,8);
        
        if isfield(new_case, 'holiday_type')
            distances(1,1) = calculate_local_distance(holiday_type_sim, ...
                                case_library{i,'HolidayType'}, new_case.holiday_type);
        else
            weighting_factors(1) = 0;
        end

        if isfield(new_case, 'price')
            distances(1,2) = calculate_euclidean_distance(case_library{i,'Price'} / max_values('Price'), ... 
                                new_case.price / max_values('Price'));
        else
            weighting_factors(2) = 0;
        end

        if isfield(new_case, 'number_persons')
            distances(1,3) = calculate_linear_distance( ...
                                case_library{i,'NumberOfPersons'} / max_values('NumberOfPersons'), ...
                                new_case.number_persons / max_values('NumberOfPersons'));
        else
            weighting_factors(3) = 0;
        end

        if isfield(new_case, 'region')
            cur_case_latlon = regions_positions(char(case_library{i,'Region'}));
    
            distances(1,4) = calculate_haversine_distance(cur_case_latlon, new_case_latlon);
            
            if distances(1,4) == -1
               distances(1,4) = 1; 
            end
        else
            weighting_factors(4) = 0;
        end

        if isfield(new_case, 'transportation')
            distances(1,5) = calculate_local_distance(transportation_sim, ...
                                    case_library{i,'Transportation'}, new_case.transportation);
        else
            weighting_factors(5) = 0;
        end

        if isfield(new_case, 'duration')
            distances(1,6) = calculate_euclidean_distance(case_library{i,'Duration'} / max_values('Duration'), ... 
                                    new_case.duration / max_values('Duration'));
        else
            weighting_factors(6) = 0;
        end

        if isfield(new_case, 'season')
            distances(1,7) = calculate_months_distance(case_library{i,'Season'}, new_case.season) / 6;
        else
            weighting_factors(7) = 0;
        end

        if isfield(new_case, 'accommodation')
            distances(1,8) = calculate_local_distance(accommodation_sim, ...
                                case_library{i,'Accommodation'}, new_case.accommodation);
        else
            weighting_factors(8) = 0;
        end

        % a)8) Utilizando a fórmula a distancia linear pesada, implemente o
        % cálculo da semelhança final e guarda o valor na variavel
        % final_similarity
        final_similarity = 1.0 - sum(weighting_factors.*distances')/sum(weighting_factors);
        
        if final_similarity >= threshold
            retrieved_indexes = [retrieved_indexes i];
            similarities = [similarities final_similarity];
        end
        
        fprintf('Case %d out of %d has a similarity of %.2f%%...\n', i, size(case_library,1), final_similarity*100);
    end
end

function [holiday_type_sim] = get_holiday_type_similarities()

    holiday_type_sim.categories = categorical({'Active', 'Bathing', 'City', 'Education', 'Language', 'Recreation', 'Skiing', 'Wandering'});

    holiday_type_sim.similarities = [
        % Active Bathing City Education Language Recreation Skiing Wandering
           1.0     0.7    0.1    0.3        0.2      0.3      0.2     0.6     % Active
           0.7     1.0    0.4    0.6        0.1      0.4      0.1     0.4     % Bathing
           0.2     0.3    1.0    0.7        0.5      0.6      0.4     0.3     % City
           0.4     0.1    0.3    1.0        0.4      0.6      0.6     0.5     % Education
           0.5     0.8    0.2    0.1        1.0      0.4      0.6     0.7     % Language
           0.8     0.3    0.2    0.4        0.6      1.0      0.7     0.6     % Recreation
           0.1     0.2    0.4    0.2        0.8      0.2      1.0     0.9     % Skiing
           0.9     0.1    0.6    0.3        0.1      0.3      0.9     1.0     % Wandering
    ];
end

function [transportation_sim] = get_transportation_similarities()

    transportation_sim.categories = categorical({'Car', 'Coach', 'Plane', 'Train'});

    transportation_sim.similarities = [
        % Car Coach Plane Train 
          1.0 0.7   0.2   0.5   % Car
          0.7 1.0   0.3   0.8   % Coach
          0.2 0.3   1.0   0.7   % Plane
          0.5 0.8   0.7   1.0   % Train
    ];
end

function [accommodation_sim] = get_accommodation_similarities()
 
    accommodation_sim.categories = categorical({'FiveStars', 'FourStars', 'HolidayFlat', 'OneStar', 'ThreeStars', 'TwoStars'});
    
    accommodation_sim.similarities = [
        % FiveStars FourStars HolidayFlat OneStar ThreeStars TwoStars 
            1.0        0.7        0.3      0.1        0.2       0.6   % FiveStars
            0.7        1.0        0.2      0.2        0.3       0.5   % FourStars
            0.3        0.2        1.0      0.3        0.6       0.7   % HolidayFlat
            0.4        0.4        0.4      1.0        0.7       0.9   % OneStar
            0.1        0.7        0.6      0.4        1.0       0.2   % ThreeStars
            0.2        0.9        0.8      0.7        0.5       1.0   % TwoStars
    ];
end

function [max_values] = get_max_values(case_library)

    key_set = {'Price', 'NumberOfPersons', 'Duration'};
    value_set = {max(case_library{:,'Price'}), max(case_library{:,'NumberOfPersons'}), max(case_library{:,'Duration'})};
    max_values = containers.Map(key_set, value_set);
end

function [res] = calculate_local_distance(sim, val1, val2)

    i1 = find(sim.categories == val1);
    i2 = find(sim.categories == val2);
    res = 1 - sim.similarities(i1,i2);
end

function [res] = calculate_months_distance(val1, val2)

    months = categorical({'January', 'February', 'March', 'April', 'May', 'June', ...
    	'July', 'August', 'September', 'October', 'November', 'December'});
    
    i1 = find(months == val1);
    i2 = find(months == val2);
 
    res = min([abs(i1 - i2), i1 - i2 + 12, i2 - i1 + 12]);
end

function [res] = calculate_linear_distance(val1, val2)

    res = (sum(abs(val1-val2)))/length(val1);
end

function [res] = calculate_euclidean_distance(val1, val2)

    res = sqrt(sum((val1-val2).^2))/length(val1);
end

function [res] = calculate_haversine_distance(latlon1, latlon2)
    
    lat1 = latlon1(1);
    lon1 = latlon1(2);

    if lat1 == 0 && lon1 == 0
        res = -1;
        return;
    end
        
    lat2 = latlon2(1);
    lon2 = latlon2(2);
    
    if lat2 == 0 && lon2 == 0
        res = -1;
        return;
    end
    
    % Adapted from https://www.mathworks.com/matlabcentral/fileexchange/38812-latlon-distance
    radius = 6371;
    lat1 = lat1 * pi/180;
    lat2 = lat2 * pi/180;
    lon1 = lon1 * pi/180;
    lon2 = lon2 * pi/180;
    delta_lat = lat2 - lat1;
    delta_lon = lon2 - lon1;
    a = sin((delta_lat)/2)^2 + cos(lat1)*cos(lat2) * sin(delta_lon/2)^2;
    c = 2 * atan2(sqrt(a),sqrt(1-a));
    distance = radius * c;
    
    % Earth circumference is used as known maximum to normalize the distance
    res = distance/40075;
end



